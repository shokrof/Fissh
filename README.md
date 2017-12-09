# Fissh
Fissh is tool for fixing corrupted files copied over ssh.

## Input:
1. File path on the client.
2. File path on the server. format: user@server:/path/to/file
## Steps:
1. createMd5sumsList for file on the clinet
2. ask server to createMd5sumsList for his file.
3. compareAndFix

## Functions
### createMd5sumsList
1. split the file into chunk(10M). chunks will be saved on /tmp/Fissh.chunks.randomtext
2. calculate md5sum for each chunk
3. output list in the format: md5sum \t chunkpath
### FixFile
#### Input
1. Input File to be fixed: filename
2. CorrectChunk: filename
3. ChunkIndex: Number
#### Description
Fix files assumes the input file to be list of equal size chunks. the chunk size equals to CorrectChunk size.
Fix files overwrite chunk at ChunkIndex with the CorrectChunk.
### clean
1. clean temporary files
### CompareAndFix
#### Input
1. Input File to be fixed: filename
2. Server md5sumList
3. Client md5sumList
#### Steps
1. compare md5sums in both lists
2. scp chunks for corrupted chunks
3. fix corrupted chunks

