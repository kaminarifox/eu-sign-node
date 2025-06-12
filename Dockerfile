FROM node:22-alpine

RUN --mount=type=cache,target=/root/.npm \
    apk add --no-cache python3 make gcc g++ gdb bash && \
    npm install -g node-gyp

RUN wget https://iit.com.ua/download/productfiles/euswi.64.tar \
    && tar -xf euswi.64.tar -C / \
    && rm euswi.64.tar

ENV LD_LIBRARY_PATH=/opt/iit/eu/sw
ENV LD_PRELOAD=/lib/libgcompat.so.0

RUN apk add --no-cache gcompat


COPY entrypoint.sh /usr/src/app/entrypoint.sh
COPY osplm.ini /opt/iit/eu/sw/osplm.ini
COPY CACertificates.p7b /opt/iit/certificates/CACertificates.p7b

RUN chmod -R 777 /opt/iit

ENTRYPOINT [ "sh", "/usr/src/app/entrypoint.sh" ]
