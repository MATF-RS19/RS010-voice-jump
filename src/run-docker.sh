#!/bin/sh

xhost +

sudo docker run --privileged -e DISPLAY=$DISPLAY  -v /tmp/.X11-unix:/tmp/.X11-unix:rw  voice_jump
