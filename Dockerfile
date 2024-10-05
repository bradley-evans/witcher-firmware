FROM expressif/idf:release-v4.4

WORKDIR /usr/src/app

RUN pip install platformio

COPY . .

CMD ["platformio", "run"]

