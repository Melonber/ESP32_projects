from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()

# Переменная для хранения состояния
status = "No_command"  # Начальное значение статуса

# Модель для входящих данных
class CommandRequest(BaseModel):
    command: str

@app.post("/check")
async def check_command(request: CommandRequest):
    global status  # Используем глобальную переменную

    if request.command in ["Send_message", "Send_Gif"]:
        status = request.command
    else:
        status = "No_command"

    return {"status": status}

@app.get("/check")  # Добавим обработчик для GET-запроса
async def get_status():
    return {"status": status}

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)
