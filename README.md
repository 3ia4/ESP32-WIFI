<div align="center">

# 🛜 **ESP32 Wi-Fi JSON**

**A small ESP32 project for testing Wi-Fi communication and sending data as JSON.**

[![ESP32](https://img.shields.io/badge/ESP32-Wi--Fi-blue?style=for-the-badge&logo=espressif)](https://www.espressif.com/)
[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![C++](https://img.shields.io/badge/C%2B%2B-Code-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)

</div>

---

## ❓ What is this?

Basically, I'm testing **Wi-Fi communication with an ESP32**.
The ESP32 connects to a Wi-Fi network and starts a small web server.
When another device on the same network sends a request, the ESP32 responds with **JSON data**.
Right now the data is fake because I don't have the sensors connected yet :D

---

## 🌐 How it works

```text
         ┌───────┐          ┌───────────┐
WIFI --> │ ESP32 │   --->   │ PC / 📱   │ --> WEB SERVER --> GET /get --> jsonData
         └───────┘          └───────────┘
```

The Concept is
The ESP32 basically acts as a tiny **local web server**.
You connect it to Wi-Fi, get its IP address, and then access:

```text
http://ESP32-IP/get
```

For example:

```text
http://1.1.1.1/get
```

---

## 🧪 Testing it

After uploading the code to the ESP32:

**1. Open Serial Monitor**

Set it to:

```text
115200 baud
```

**2. Wait for the ESP32 to connect**

You should get something like:

```text
........
Connected
IP : 1.1.1.1
```

**3. Open the IP address**

From another device connected to the same Wi-Fi:

```text
http://1.1.1.1/get
```

You should see:

```json
{
  "temp": 30,
  "humidity": 50,
  "light": 400
}
```

---

## 🧠 Why JSON?

JSON makes the data easy for other programs to understand.
Like sharing data across multiple pc's to maybe an ai or data center or something its easier
to read and analyize the data and give output.

---

<div align="center">
  
</div>
