#ifndef LUCIA_LOG_HPP_
#define LUCIA_LOG_HPP_

#include <filesystem>
#include <fstream>
#include <ctime>
#include <iostream>

namespace lucia {
    class Logger {
        private:
            std::filesystem::path log_file;

            template<class... Args>
            auto write_file(Args... args) const -> void {
                if (log_file.empty()) return;

                const time_t time = std::time(nullptr);

                std::ofstream file(this->log_file, std::ios_base::app);

                (file << "[" << time << "] "), (file << ... << args) << "\n";
                file.close();
            }

        public:
            Logger(const std::filesystem::path &log_file) :
                log_file(log_file) {};

            Logger() {};

            template<class... Args>
            auto print(Args... args) const -> void {
                this->write_file(args...);
                (std::cout << ... << args) << "\n";
            }

            template<class... Args>
            auto info(Args... args) const -> void {
                this->print("[i] ", (... << args));
            }

            template<class... Args>
            auto warning(Args... args) const -> void {
                this->print("[*] ", (... << args));
            }

            template<class... Args>
            auto error(Args... args) const -> void {
                this->write_file("[!] ", args...);
                (std::cerr << "[!] " << (... << args)) << "\n";
            }
    };
}

#endif // LUCIA_LOG_HPP_