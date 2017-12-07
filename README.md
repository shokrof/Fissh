# Fissh
Fissh is tool for fixing corrupted files copied over ssh.

## Functions Supported
### createMd5sumsList
1. split the file into chunk(10M). chunks will be saved on /tmp/Fissh.chunks.randomtext
2. calculate md5sum for each chunk
3. output list in the format: chunkpath \t md5sum
### 
### clean
1. clean temporary files 
### Fissh
#### Input:
1. File path on the client.
2. File path on the server. format: user@server:/path/to/file
#### Steps:
1. createMd5sumsList for file on the clinet
2. ask server to createMd5sumsList for his file.
3. compare md5sums with servers md5sums and scp corrupted chunks and fix on the main file