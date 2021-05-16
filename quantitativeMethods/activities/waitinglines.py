import random
import pandas
from datetime import datetime, timedelta

HEADERS = [
    "Client",
    "Interarrival Time",
    "Hour of arrival",
    "Transaction time",
    "Service begins",
    "Service ends at",
    "Client waiting time",
    "ATM idle time",
]

now = datetime.now()
random.seed(now.microsecond)
hour = now.replace(microsecond=0, second=0, minute=0)
start_time = hour
last_used = hour
data = list()
wait_sum = timedelta(minutes=0)
trans_sum = timedelta(minutes=0)
idle_sum = timedelta(minutes=0)
waited = 0
for x in range(1,11):
    arrival_time = timedelta(minutes=0)
    transaction_time = timedelta(minutes=int(random.random()*100))
    if x > 1:
        arrival_time = timedelta(minutes=int(random.random()*100))
        hour += arrival_time

    if last_used < hour:
        waiting_time = timedelta(minutes=0)
        idle_time = hour - last_used
        last_used = hour
    else:
        waiting_time = last_used - hour
        idle_time = timedelta(minutes=0)
        waited += 1
    finished = last_used + transaction_time

    data.append([
        x,
        arrival_time.seconds/60,
        hour.strftime("%H:%M"),
        transaction_time.seconds/60,
        last_used.strftime("%H:%M"),
        finished.strftime("%H:%M"),
        waiting_time.seconds/60,
        idle_time.seconds/60,
    ])
    last_used = finished
    wait_sum += waiting_time
    trans_sum += transaction_time
    idle_sum += idle_time

print(pandas.DataFrame(data, columns = HEADERS))
print("Average waiting time per client: %f minutes, %f minutes on average percentage" % (wait_sum.seconds/60, wait_sum.seconds/600))
print("Probability that a client will wait in the line: %f waiting clients, %f percentage" % (waited, waited/10))
print("Percentage of the ATM's idle time: %f inactive/%f total, %f percentage" % (
    idle_time.seconds/60,
    (finished-start_time).seconds/60,
    idle_time.seconds/(60*(finished-start_time).seconds/60))
)
print("Average transaction time: %f minutes, %f minutes on average" % (trans_sum.seconds/60, trans_sum.seconds/600))
