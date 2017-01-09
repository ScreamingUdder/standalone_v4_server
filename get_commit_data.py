from kafka import KafkaConsumer, KafkaProducer, TopicPartition
import json
import time

BROKER1 = "tenten:9092"
BROKER2 = "sakura:9092"

PV_NAME = "mytestDouble"
# PV_NAME = "THIS_PC:TEMP"

topic = TopicPartition(PV_NAME, 0)

consumer = KafkaConsumer(bootstrap_servers=[BROKER1, BROKER2])
consumer.assign([topic])
consumer.seek_to_end(topic)
end_pos = consumer.position(topic)

print "End %d" % end_pos

consumer.seek(topic, end_pos - 1)

data = list()

while len(data) == 0:
    data = consumer.poll()

print data

consumer.close()