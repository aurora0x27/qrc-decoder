#ifndef BUFFER_H
#define BUFFER_H
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <vector>

namespace qqmusic::utils {
class buffer : public std::vector<uint8_t> {
public:
    buffer() = default;
    buffer(size_t size) : std::vector<uint8_t>(size) { };
    buffer(const uint8_t* src_head, size_t src_size) : std::vector<uint8_t>(src_head, src_head + src_size) { };
    ~buffer() = default;
    void append(const void* src_data_buf, size_t data_buf_size) {
        this->insert(this->end(), (uint8_t*)src_data_buf, (uint8_t*)src_data_buf + data_buf_size);
    };
};

// this function is specially writen as http request callback
size_t http_writebuf(void* src_data_buf,
                     size_t data_block_size,
                     size_t data_block_num,
                     void* buffer_ptr);
} // namespace qqmusic::utils
#endif // !BUFFER_H
