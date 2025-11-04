// Interface.h
// HTML/CSS/JS for ESP32 WebSocket control interface

#ifndef INTERFACE_H
#define INTERFACE_H

const char MAIN_page[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>ESP32 Car Control</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial; user-select: none; -webkit-user-select: none; }
    .btn { width: 60px; height: 60px; font-size: 2em; margin: 10px; border-radius: 10px; border: none; background: #2196F3; color: white; }
    .btn:active { background: #0b7dda; }
    #debug { width: 90vw; height: 120px; border: 1px solid #ccc; margin-top: 20px; overflow-y: auto; background: #f9f9f9; padding: 10px; }
  </style>
</head>
<body>
  <div style="text-align:center;">
    <button class="btn" id="f" onmousedown="sendCmd('move','f')" onmouseup="sendCmd('move','s')" ontouchstart="sendCmd('move','f')" ontouchend="sendCmd('move','s')">F</button><br>
    <button class="btn" id="l" onmousedown="sendCmd('move','l')" onmouseup="sendCmd('move','s')" ontouchstart="sendCmd('move','l')" ontouchend="sendCmd('move','s')">L</button>
    <button class="btn" id="s" onmousedown="sendCmd('move','s')" onmouseup="sendCmd('move','s')" ontouchstart="sendCmd('move','s')" ontouchend="sendCmd('move','s')">S</button>
    <button class="btn" id="r" onmousedown="sendCmd('move','r')" onmouseup="sendCmd('move','s')" ontouchstart="sendCmd('move','r')" ontouchend="sendCmd('move','s')">R</button><br>
    <button class="btn" id="b" onmousedown="sendCmd('move','b')" onmouseup="sendCmd('move','s')" ontouchstart="sendCmd('move','b')" ontouchend="sendCmd('move','s')">B</button>

    <hr>
    <input type="number" id="time" placeholder="time" value="500"><br>
    <button class="btn" id="fs" onclick="sendCmd('fs',document.getElementById('time').value)">F_S</button><br>
    <button class="btn" id="bs" onclick="sendCmd('bs',document.getElementById('time').value)">B_S</button><br>

    <hr>
    <input type="number" id="angle" placeholder="time" value="90"><br>
    <button class="btn" id="turn" onclick="sendCmd('turn',document.getElementById('angle').value)">turn </button><br>




    <div id="debug"></div>
  </div>
  <script>
    var socket;
    window.onload = function() {
      socket = new WebSocket('ws://' + window.location.hostname + ":81");
      socket.onopen = function() { console.log('WebSocket Connected'); };
      socket.onmessage = function(event) {
        try {
          var data = JSON.parse(event.data);
          if (data.key === 'debug') {
            document.getElementById('debug').innerHTML += data.msg + '<br>';
            document.getElementById('debug').scrollTop = document.getElementById('debug').scrollHeight;
          }
        } catch (e) { console.log('Invalid JSON:', event.data); }
      };
      socket.onclose = function() { console.log('WebSocket Closed'); };
    };
    function sendCmd(key, value) {
      if (socket && socket.readyState === 1) {
        socket.send(JSON.stringify({ key: key, value: value }));
      }
    }
  </script>
</body>
</html>
)rawliteral";

#endif // INTERFACE_H
