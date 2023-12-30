#include "include/data_handler.h"
#include "include/data.h"

data_handler::data_handler() {
    data_array = new std::vector<data *>;
    test_data = new std::vector<data *>;
    training_data = new std::vector<data *>;
    validation_data = new std::vector<data *>;
};

data_handler::~data_handler() {
    // FREE Dynamically Allocated stuff
};

void data_handler::read_feature_vector(std::string path) {
    uint32_t header[4];         // MAGIC|NUM IMAGES|ROWSIZE|COLSIZE
    unsigned char bytes[4];
    FILE *f = fopen(path.c_str(), "r");
    if (f) {
        for (int i = 0; i < 4; i++) {
            if (fread(bytes, sizeof(bytes), 1, f)) {
                header[i] = convert_to_litte_endian(bytes);
            }
        }
        printf("Done getting file header.\n");
        int image_size = header[2] * header[3];
        for (int i = 0; i < header[1]; i++) {
            data *d = new data();
            uint8_t element[1];
            for (int j = 0; j < image_size; j++) {
                if (fread(element, sizeof(element), 1, f)) {
                    d->append_to_feature_vector(element[0]);
                } else {
                    printf("Error reading from file.\n");
                    exit(1);
                }
            }
            data_array->push_back(d);
        }
        printf("Successfully read and stored %lu feature vectors.\n", data_array->size());
    } else {
        printf("Could not find the file.\n");
        exit(1);
    }
};

void data_handler::read_feature_labels(std::string path) {};

void data_handler::split_data() {};

void data_handler::count_classes() {};

uint32_t data_handler::convert_to_litte_endian(const unsigned char *bytes) {};

std::vector<data *> *data_handler::get_training_data() {};

std::vector<data *> *data_handler::get_test_data() {};

std::vector<data *> *data_handler::get_validation_data() {};