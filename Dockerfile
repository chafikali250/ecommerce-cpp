# Stage 1: Compilation
FROM ubuntu:22.04 AS builder
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    g++ \
    make \
    wget \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY main.cpp ./
RUN wget -q https://raw.githubusercontent.com/yhirose/cpp-httplib/master/httplib.h
RUN g++ -O3 -std=c++17 main.cpp -o ecommerce_app -pthread

# Stage 2: Runtime
FROM ubuntu:22.04
RUN apt-get update && apt-get install -y \
    libstdc++6 \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY --from=builder /app/ecommerce_app .

EXPOSE 5050
CMD ["./ecommerce_app"]
