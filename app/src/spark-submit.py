from pyspark import SparkConf, SparkContext


df = spark.read.json("/app/data/*.log")
df.printSchema()
df.show()

# https://stackoverflow.com/questions/34216390/how-to-see-the-contents-of-each-partition-in-an-rdd-in-pyspark/34216391
