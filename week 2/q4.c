#define READING   0x01
#define WRITING   0x02
#define AS_BYTES  0x04
#define AS_BLOCKS 0x08
#define LOCKED    0x10


unsigned char device;

int main() {
    // a
    device = device | READING | LOCKED | AS_BYTES;
    // does the same as above.
    device |= READING;
    device |= LOCKED;
    device |= AS_BYTES;
    // does the same too
    device |= (READING | LOCKED | AS_BYTES);
    
    // b
    device = device | WRITING | LOCKED | AS_BLOCKS;
    
    // c 
    device |= LOCKED;
    
    // d
    device = device & (~LOCKED);
    
    // e -> always sets reading to false and writing to true.
    // setting reading to false
    device = device & (~READING);
    // set writing to true
    device = device | WRITING;
    
    // combine into one line
    device = (device & (~READING)) | WRITING;
    
    // f -> dependent on original value of device
    // flip both READING and WRITING flags.
    // READING first
    device = device ^ READING;
    
    // then WRIITNG
    device = device ^ WRITING;
    
}




