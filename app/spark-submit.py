import os
import json
from pyspark import SparkContext
from pyspark.sql.session import SparkSession
import src.autogen as ag

os.chdir('/app')

sparkSession: SparkSession = spark
sparkContext: SparkContext = sc

jsonStrings = sparkContext.wholeTextFiles('./data/*.log')

# add the file name to the object that will be parsed to a LogFile
jsons = jsonStrings.map(lambda pair: {**{"file": pair[0]}, **json.loads(pair[1])})

# parse to LogFile
objects = jsons.map(lambda object: ag.logfile_from_dict(object))

# calculate how many times each team won...
rounds = objects.flatMap(lambda o: o.rounds)
winners = rounds.groupBy(lambda r: r.winner).map(lambda x: (x[0], len(x[1])))
winners.collect()

# https://stackoverflow.com/questions/34216390/how-to-see-the-contents-of-each-partition-in-an-rdd-in-pyspark/34216391
