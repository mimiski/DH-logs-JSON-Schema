from jsonschema import validate
import json
import os

schemaFile = open('schema.json')
schema = json.load(schemaFile)

# If no exception is raised by validate(), the instance is valid.
for fileName in [f for f in os.listdir(".") if f.endswith("log")]:
  dataFile = open(fileName, encoding="cp1252")
  data = json.load(dataFile)
  validate(instance=data, schema=schema)

