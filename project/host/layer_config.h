#include "../device/hw_param.cl"

/*
// VGG-16 Configuration
unsigned layer_config[][25] = {{0,
							224, 224, VEC_SIZE, 3, 3, VEC_SIZE, 64, 64,
							0,
							224, 224, 64, 1, 1, 0, 1,
							0, 224, 224, 64, 0, 0,
							0,
							1},//Layer-1 (conv1_1)
							{0,
							224, 224, 64, 3, 3, 64, 64, 64,
							1,
							224, 224, 64, 1, 1, 0, 1,
							1, 112, 112, 64, 2, 2,
							0,
							0},//Layer-2 (conv1_2)
							{0,
							112, 112, 64, 3, 3, 64, 128, 128,
							0,
							112, 112, 128, 1, 1, 0, 1,
							0, 112, 112, 128, 0, 0,
							0,
							1},//Layer-3 (conv2_1)
							{0,
							112, 112, 128, 3, 3, 128, 128, 128,
							1,
							112, 112, 128, 1, 1, 0, 1,
							1, 56, 56, 128, 2, 2,
							0,
							0},//Layer-4 (conv2_2)
							{0,
							56, 56, 128, 3, 3, 128, 256, 256,
							0,
							56, 56, 256, 1, 1, 0, 1,
							0, 56, 56, 256, 0, 0,
							0,
							1},//Layer-5 (conv3_1)
							{0,
							56, 56, 256, 3, 3, 256, 256, 256,
							1,
							56, 56, 256, 1, 1, 0, 1,
							0, 56, 56, 256, 0, 0,
							0,
							0},//Layer-6 (conv3_2)
							{0,
							56, 56, 256, 3, 3, 256, 256, 256,
							0,
							56, 56, 256, 1, 1, 0, 1,
							1, 28, 28, 256, 2, 2,
							0,
							1},//Layer-7 (conv3_3)
							{0,
							28, 28, 256, 3, 3, 256, 512, 512,
							1,
							28, 28, 512, 1, 1, 0, 1,
							0, 28, 28, 512, 0, 0,
							0,
							0},//Layer-8  (conv4_1)
							{0,
							28, 28, 512, 3, 3, 512, 512, 512,
							0,
							28, 28, 512, 1, 1, 0, 1,
							0, 28, 28, 512, 0, 0,
							0,
							1},//Layer-9  (conv4_2)
							{0,
							28, 28, 512, 3, 3, 512, 512, 512,
							1,
							28, 28, 512, 1, 1, 0, 1,
							1, 14, 14, 512, 2, 2,
							0,
							0},//Layer-10 (conv4_3)
							{0,
							14, 14, 512, 3, 3, 512, 512, 512,
							0,
							14, 14, 512, 1, 1, 0, 1,
							0, 14, 14, 512, 0, 0,
							0,
							1},//Layer-11  (conv5_1)
							{0,
							14, 14, 512, 3, 3, 512, 512, 512,
							1,
							14, 14, 512, 1, 1, 0, 1,
							0, 14, 14, 512, 0, 0,
							0,
							0},//Layer-12  (conv5_2)
							{0,
							14, 14, 512, 3, 3, 512, 512, 512,
							0,
							14, 14, 512, 1, 1, 0, 1,
							1, 7, 7, 512, 2, 2,
							0,
							2},//Layer-13  (conv5_3)    Note: for last conv layer, outputs are write to fc buffer
							{1,
							28, 28, 512, 7, 7, 512, 4096, 4096,
							2,
							4, 4, 4096, 7, 0, 0, 1,
							0, 4, 4, 4096, 0, 0,
							0,
							3},//Layer-14  (fc6)							
							{1,
							4, 4, 4096, 1, 1, 4096, 4096, 4096,
							3,
							4, 4, 4096, 1, 0, 0, 1,
							0, 4, 4, 4096, 0, 0,
							0,
							2},//Layer-15  (fc7)
							{1,
							4, 4, 4096, 1, 1, 4096, 1024, 1024,
							2,
							4, 4, 1024, 1, 0, 0, 0,
							0, 4, 4, 1024, 0, 0,
							0,
							3}//Layer-16  (fc8)		
							};

unsigned input_config[4] = {224, 224, 3, 16};

//unsigned output_config[3] = {112, 112, 64};//Layer-2

unsigned output_config[3] = {1, 1, 1024};//Layer-16
*/


// Alexnet Configuration
unsigned layer_config[][25] = {{0,
							227, 227, VEC_SIZE, 11, 11, VEC_SIZE, 96, 96,  //Note: for dim3 must be consistent with VEC_SIZE
							0,
							55, 55, 96, 4, 0, 0, 1,
							1, 27, 27, 96, 3, 2,
							1,
							1},//Layer-1
							{0,
							27, 27, 96, 5, 5, 48, 256, 256,
							0,
							27, 27, 256, 1, 2, 1, 1,
							1, 13, 13, 256, 3, 2,
							1,
							1},//Layer-2
							{0,
							13, 13, 256, 3, 3, 256, 384, 384,
							0,
							13, 13, 384, 1, 1, 0, 1,
							0, 13, 13, 384, 0, 0,
							0,
							1},//Layer-3
							{0,
							13, 13, 384, 3, 3, 192, 384, 384,
							1,
							13, 13, 384, 1, 1, 1, 1,
							0, 13, 13, 384, 0, 0,
							0,
							0},//Layer-4
							{0,
							13, 13, 384, 3, 3, 192, 256, 256,
							0,
							13, 13, 256, 1, 1, 1, 1,
							1, 6, 6, 256, 3, 2,
							0,
							2},//Layer-5  Note: for last conv layer, outputs are write to fc buffer
							{1,
							24, 24, 256, 6, 6, 256, 4096, 4096,  // Note: The input size (dim1/dim2) is the combined data size (batched)
							2,
							4, 4, 4096, 6, 0, 0, 1,
							0, 4, 4, 4096, 0, 0,
							0,
							3},//Layer-6 fc
							{1,
							4, 4, 4096, 1, 1, 4096, 4096, 4096,
							3,
							4, 4, 4096, 1, 0, 0, 1,
							0, 4, 4, 4096, 0, 0,
							0,
							2},//Layer-7 fc
							{1,
							4, 4, 4096, 1, 1, 4096, 1024, 1024,
							2,
							4, 4, 1024, 1, 0, 0, 0,
							0, 4, 4, 1024, 0, 0,
							0,
							3}//Layer-8 fc
							};

unsigned input_config[5] = {227, 227, 3, 16}; //original image size(dim1, dim2, dim3), batch size

//unsigned output_config[3] = {27, 27, 96};//Layer-1

//unsigned output_config[3] = {6, 6, 256};//Layer-5

//unsigned output_config[3] = {1, 1, 4096};//Layer-6

unsigned output_config[3] = {1, 1, 1024};//Layer-8  Note: only one result is extracted and verified

