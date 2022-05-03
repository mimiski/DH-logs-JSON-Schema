from pyspark import SparkConf, SparkContext

conf = SparkConf().setAppName("stats calculation")
sparkContext = SparkContext(conf=conf)
sparkContext.setLogLevel("DEBUG")



patientsRdd = sparkContext.parallelize(patients)

# https://stackoverflow.com/questions/34216390/how-to-see-the-contents-of-each-partition-in-an-rdd-in-pyspark/34216391
triplesPerPartitionRdd = patientsRdd.glom().flatMap(lambda patientsInPartition: [p.getRdfTriples(N) for p in patientsInPartition])
serializedRdd = triplesPerPartitionRdd.map(lambda triplesPerPartition: RDFSerializer.serialize(triplesPerPartition))
serializedRdd.saveAsTextFile("serialized_" + str(N))
