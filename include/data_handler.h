#ifndef SIMPLEMLMODEL_DATA_HANDLER_H
#define SIMPLEMLMODEL_DATA_HANDLER_H

/* reading the data, splitting the data, count the number of unique classes,
 * convert to little endian, pass around the test, train, validation data */

#include <fstream>
#include <cstdint>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>

#include "data.h"

class data_handler {
    std::vector<data *> *data_array;    // all the data (pre-split)
    std::vector<data *> *training_data;
    std::vector<data *> *test_data;
    std::vector<data *> *validation_data;

    int num_classes;
    int feature_vector_size;
    std::map<uint8_t, int> class_map;

    const double TRAIN_SET_PERCENT = 0.75;
    const double TEST_SET_PERCENT = 0.20;
    const double VALIDATION_PERCENT = 0.05;

public:
    data_handler();
    ~data_handler();

    void read_feature_vector(std::string path);
    void read_feature_labels(std::string path);
    void split_data();
    void count_classes();

    uint32_t convert_to_litte_endian(const unsigned char *bytes);

    std::vector<data *> *get_training_data();
    std::vector<data *> *get_test_data();
    std::vector<data *> *get_validation_data();
};

#endif //SIMPLEMLMODEL_DATA_HANDLER_H
