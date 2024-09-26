import React from 'react';
import { View, Text, Button, StyleSheet, Alert, TouchableOpacity, Image } from 'react-native';

const App = () => {
  const esp32Ip = "";//IP
  const turnOnLEDs = async () => {
    try {
      const response = await fetch(`${esp32Ip}/led/on`);
      if (response.ok) {
        //Alert.alert("Success", "All LEDs are ON");
      } else {
        Alert.alert("Error", "Failed to turn ON LEDs");
      }
    } catch (error) {
      Alert.alert("Error", "Unable to connect to ESP32");
      console.error(error);
    }
  };

  const turnOffLEDs = async () => {
    try {
      const response = await fetch(`${esp32Ip}/led/off`);
      if (response.ok) {
        //Alert.alert("Success", "All LEDs are OFF");
      } else {
        Alert.alert("Error", "Failed to turn OFF LEDs");
      }
    } catch (error) {
      Alert.alert("Error", "Unable to connect to ESP32");
      console.error(error);
    }
  };
  
  const turnOnBlinking = async () => {
    try {
      const response = await fetch(`${esp32Ip}/led/blinking`);
      
      if (response.ok) {
        //Alert.alert("HONEY", "Please wait till dancing will be stopped");
      } else {
        Alert.alert("Error", "Failed to turn OFF LEDs");
      }
    } catch (error) {
      Alert.alert("Error", "Unable to connect to ESP32");
      console.error(error);
    }
  };

return (
    <View style={styles.container}>

      <Text style={styles.title}>你好!</Text>
      <TouchableOpacity style={styles.button} onPress={turnOnLEDs}>
        <Text style={styles.buttonText}>Turn ON LEDs  🟢</Text>
      </TouchableOpacity>
      <TouchableOpacity style={styles.button} onPress={turnOffLEDs}>
        <Text style={styles.buttonText}>Turn OFF LEDs 🔴</Text>
      </TouchableOpacity>
      <TouchableOpacity style={styles.button} onPress={turnOnBlinking}>
        <Text style={styles.buttonText}>Start Dancing🕺</Text>
      </TouchableOpacity>

      <Image 
  source={{ uri: 'https://i.gifer.com/origin/88/883d968d9e1a7f29af36cf429164c786_w200.gif' }} 
  style={{ 
    width: 200, 
    height: 200, 
    position: 'absolute', 
    bottom: 0, 
    left: '50%', 
    marginLeft: -100 // Половина ширины изображения для центрирования
  }} 
/>

    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#FFCC99',
  },
  title: {
    fontSize: 24,
    marginBottom: 20,
  },
  title_2: {
    fontSize: 14,
    marginBottom: 20,
    textAlign:'center',
  },
  button: {
    backgroundColor: '#04AA6D', // Зеленый
    borderRadius: 5,            // Радиус скругления углов
    paddingVertical: 15,        // Вертикальный отступ
    paddingHorizontal: 32,      // Горизонтальный отступ
    alignItems: 'center',       // Центрируем текст
    marginVertical: 10,         // Отступ между кнопками
  },
  buttonText: {
    color: 'white',             // Цвет текста
    fontSize: 16,               // Размер шрифта
    textAlign: 'center',        // Выравнивание текста
  },
});

export default App;
