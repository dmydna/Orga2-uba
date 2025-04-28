#include "type.h"

fat32_t* new_fat32(){
    fat32_t* fat32 = (fat32_t*)malloc(sizeof(fat32_t)); 
    fat32->type = TypeFAT32;
    return fat32;  
};

ext4_t* new_ext4(){
    ext4_t* ext4 = (ext4_t*)malloc(sizeof(ext4)); 
    ext4->type = TypeEXT4;
    return ext4;  
};

ntfs_t* new_ntfs(){
    ntfs_t* ntfs = (ntfs_t*)malloc(sizeof(ntfs_t)); 
    ntfs->type = TypeNTFS;
    return ntfs;  
};

fat32_t* copy_fat32(fat32_t* file){
    fat32_t* cpy_fat32 = (fat32_t*)malloc(sizeof(fat32_t));
    cpy_fat32->type = file->type;
    return cpy_fat32;
};

ext4_t* copy_ext4(ext4_t* file){
    ext4_t* cpy_ext4 = (ext4_t*)malloc(sizeof(ext4_t));
    cpy_ext4->type = file->type;
    return cpy_ext4;
}


ntfs_t* copy_ntfs(ntfs_t* file){
    ntfs_t* cpy_ntfs = (ntfs_t*)malloc(sizeof(ntfs_t));
    cpy_ntfs->type = file->type;
    return cpy_ntfs;
}


void rm_fat32(fat32_t* file){
    free(file);
}


void rm_ext4(ext4_t* file){
    free(file);
}


void rm_ntfs(ntfs_t* file){
    free(file);
}
