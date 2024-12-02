FROM debian:bookworm

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y git build-essential cmake zlib1g-dev libssl-dev && \
    apt-get clean

WORKDIR /app

RUN git clone --depth 1 https://github.com/brainboxdotcc/DPP /app/dpp
WORKDIR /app/dpp
RUN mkdir build && cd build && cmake .. && cmake --build . -j8 && make install

WORKDIR /app

COPY ../../../ /app/
COPY ../../.ohptnlaurent /app/
RUN chmod +x /app/envs/dev/run.sh

CMD ["/app/envs/dev/run.sh"]
