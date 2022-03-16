import random

def ChooseItem(options):
	if len(options) > 0:
		choice = random.choice(options)
		return {'QueueName' : choice[4], 'ItemRank' : choice[5]}
	return None

