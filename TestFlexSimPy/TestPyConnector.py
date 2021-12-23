import random

def TestPy(item, port):
	port += 1
	return "Hello World!!!"


def ChooseItem(jobs):
	print("Jobs: ", jobs)
	if len(jobs) > 0:
		choice = random.choice(jobs)
		return {"QueueName": choice[4], "ItemRank": choice[5]}
	return None


