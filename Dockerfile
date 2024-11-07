FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    g++ \
    make \
    git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /usr/src/app

RUN git clone https://github.com/yy-mokhtar/Queues-using-Stacks .

RUN make

CMD ./Queue_attempt_1 && ./Queue_attempt_2