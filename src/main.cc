#include <fstream>
#include <utils/buffer.h>
#include <utils/qrcdecoder.h>
#include <utils/ulog.h>

int main(int argc, char** argv) {
    if (argc == 1) {
        ulog(MSG_ERROR, "Too few arguments...exiting...");
        ulog(MSG_INFO, "usage: %s <file1> [<file2> <file3> ...]", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        std::fstream input_file;
        input_file.open(argv[i], std::ios::binary | std::ios::in);

        ulog(MSG_INFO, "reading file begin...");
        input_file.seekg(0, std::ios::end);
        size_t input_file_size = input_file.tellg();
        input_file.seekg(0, std::ios::beg);
        qqmusic::utils::buffer in_buf(input_file_size);
        input_file.read((char*) in_buf.data(), (long) in_buf.size());

        ulog(MSG_INFO, "reading file end...");

        input_file.close();

        qqmusic::utils::buffer out_buf;

        ulog(MSG_INFO, "decode file %s begin", argv[i]);

        // decode...
        auto res = qqmusic::utils::qrc_decode(in_buf, out_buf, qqmusic::utils::qrc_type::local);
        if (res.has_value()) {
            ulog(MSG_ERROR, res.value().c_str());
        }

        ulog(MSG_INFO, "decode file %s end", argv[i]);

        std::fstream output_file;
        std::string output_file_name = (std::string) argv[i] + ".decode";
        ulog(MSG_INFO, "output file is %s", output_file_name.c_str());
        output_file.open(output_file_name, std::ios::out);
        std::string output_file_buf((char*) out_buf.data(), out_buf.size());
        ulog(MSG_INFO, "writing file begin...");
        output_file.write(output_file_buf.c_str(), (long) output_file_buf.size());
        ulog(MSG_INFO, "writing file end...");

        output_file.close();
    }

    return 0;
}
