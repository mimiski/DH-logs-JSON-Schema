import os
import json
from pyspark import SparkContext
from pyspark.sql.session import SparkSession
import src.autogen as ag

os.chdir('/app')

sparkSession: SparkSession = spark
sparkContext: SparkContext = sc

jsonStrings = sparkContext.wholeTextFiles('./data/*.log')
# jsonsStrings.foreach(lambda x: y: print(x))
jsons = jsonStrings.map(lambda pair: {**json.loads(pair[1]), **{"file": pair[0]}})
jsons.take(1)
objects = jsons.map(lambda object: ag.coordinate_from_dict(object))
objects.take(1)
winners = objects.map(lambda o: o.server.name)
winners.collect()

# https://stackoverflow.com/questions/34216390/how-to-see-the-contents-of-each-partition-in-an-rdd-in-pyspark/34216391
