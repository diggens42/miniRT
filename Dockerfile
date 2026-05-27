FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
	build-essential \
	cmake \
	git \
	libglfw3-dev \
	libgl-dev \
	&& rm -rf /var/lib/apt/lists/*

WORKDIR /miniRT

COPY . .

RUN git submodule update --init --recursive

RUN make all
