#Usage ./createMd5sumsList.sh <input file>
#list will be printed on the stdout
inputFile=$1

echo $inputFile
cat $inputFile | parallel --gnu -k --pipe --block 5M --files cat | parallel --gnu md5sum {}

