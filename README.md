# fileDelivery
Vugen script to deliver extra files to load generators to be consumed by JMeter scripts.  this script must execute on each LG prior to launch of the JMeter scripts.

target_folder - the folder on the LG where you want the files copied
file1 - the name of the file to copy to the target_folder

The above arguments can be passed via command line.  refer to LR/Vugen for documentation on how to accomplish.

This script assumes only one file being copied but can easily modified to have more files.
