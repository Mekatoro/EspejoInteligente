# EspejoInteligente
Implementación de un espejo inteligente usando el software libre MAGIC MIRROR y combinando la raspberry con un microcontrolador arduino para controlar dispositivos.

* Se requiere una raspberry 3 o la raspberry 4 con sistema operativo Raspberry OS
- se puede revisar la documentacion en la página oficial de raspberry https://www.raspberrypi.org/software/

* Actualizamos el SO de la raspberry con los comandos: 
sudo apt-get update 
sudo apt-get upgrade

* Se reinicia la raspberry

* Se requiere descargar e instalar el programa Magic Mirror, para ello ejecutamos las siguientes instrucciones en la consola de linux en la raspberry
- curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash -
- sudo apt install -y nodejs
- git clone https://github.com/MichMich/MagicMirror
- cd MagicMirror/
- npm install
- cp config/config.js.sample config/config.js
- npm start

A partir de aquí se puede usar MAGIC MIRROR pero si se lo quiere modificar o cambiar los módulo se los puede hacer usando módulos creados por la comunidad
https://github.com/MichMich/MagicMirror/wiki/3rd-party-modules

Finalmente se carga el código magicMirror.ino en el arduino para que lea los sensores y controle los actuadores.

Luego puede ejecutarse el programa .py en la raspberry haciendo doble click o en la consola con el comando:
python comunicacion.py


