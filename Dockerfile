FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y \
    git g++ cmake valgrind clang-format cppcheck gcovr

COPY .  /code
WORKDIR /code/src

CMD bash
