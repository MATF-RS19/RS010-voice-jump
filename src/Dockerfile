FROM ubuntu

ARG DEBIAN_FRONTEND= noninteractive

RUN apt-get update && \
    apt-get -y install gcc g++ && \
    apt-get -y install build-essential && \
    apt-get -y install qt5-default && \
    apt-get -y install libx11-xcb1 && \
    apt-get -y install x11-apps && \
    apt-get -y install libqt5multimedia5 && \
    apt-get -y install qtmultimedia5-dev && \
    apt-get -y install fftw3-dev && \
    apt-get -qq -y install cmake



COPY . /usr/workdir

WORKDIR /usr/workdir

WORKDIR /usr/workdir/build

RUN cmake -G "Unix Makefiles" .. && \
    make

CMD ["./voice_jump"]
