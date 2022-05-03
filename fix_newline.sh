for fileName in `ls | grep log`;
do
  echo $fileName
  sed -i "s/\n\n/\n/g" $fileName;
done
