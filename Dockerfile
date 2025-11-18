FROM ubuntu:22.04

# Install required packages
RUN apt update && apt install -y \
    build-essential \
    cmake \
    git \
    wget \
    unzip \
    libx11-dev \
    libxinerama-dev \
    libxrandr-dev \
    libxcursor-dev \
    libfreetype6-dev \
    libglu1-mesa-dev \
    libasound2-dev \
    libcurl4-openssl-dev \
    patchelf

# Install JUCE
WORKDIR /root
RUN git clone --depth 1 https://github.com/juce-framework/JUCE.git juce

# Copy builder files
WORKDIR /app
COPY . .

RUN chmod +x build.sh
RUN chmod +x entrypoint.sh

ENTRYPOINT ["./entrypoint.sh"]
