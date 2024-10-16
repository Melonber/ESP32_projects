import telebot
import requests
import time

API_URL = "http://localhost:8000/check"  # URL вашего FastAPI приложения
TOKEN = ""

bot = telebot.TeleBot(TOKEN)

# Храним CHAT_ID пользователей
user_chat_ids = {}

@bot.message_handler(commands=['start'])
def send_welcome(message):
    user_chat_ids[message.chat.id] = message.chat.id
    bot.reply_to(message, "Я готов !")

@bot.message_handler(func=lambda message: True)
def check_api(message):
    user_chat_ids[message.chat.id] = message.chat.id

    # Отправляем POST-запрос с желаемым значением command
    should_send = "Send_message"  # Замените на вашу логику, чтобы определить, когда отправлять сообщение

    response = requests.post(API_URL, json={"command": should_send})

    if response.status_code == 200:
        data = response.json()
        if data.get("status") == "Send_message":
            bot.send_message(message.chat.id, "Кнопка была нажата")
        elif data.get("status") == "Send_Gif":
            bot.send_animation(message.chat.id, "URL_вашей_гифки")  # Замените на ваш URL

def check_status():
    while True:
        response = requests.get(API_URL)
        if response.status_code == 200:
            data = response.json()
            if data.get("status") == "Send_message":
                for chat_id in user_chat_ids:
                    bot.send_message(chat_id, "Даров, че хотел ?")
                # Сброс статуса на "No_command"
                requests.post(API_URL, json={"command": "No_command"})
            elif data.get("status") == "Send_Gif":
                for chat_id in user_chat_ids:
                    bot.send_message(chat_id, "Ты хотел гифку, держи котика !")
                    bot.send_animation(chat_id, "https://media.tenor.com/i740rUVh05gAAAAM/kitten-kitty.gif")  # Замените на ваш URL
                # Сброс статуса на "No_command"
                requests.post(API_URL, json={"command": "No_command"})

        time.sleep(5)  # Проверяем статус каждые 5 секунд

# Запускаем проверку статуса в отдельном потоке
import threading
threading.Thread(target=check_status, daemon=True).start()

bot.polling()
