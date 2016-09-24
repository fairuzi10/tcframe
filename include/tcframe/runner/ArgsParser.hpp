#pragma once

#include <cstdio>
#include <cstring>
#include <getopt.h>
#include <stdexcept>
#include <string>

#include "Args.hpp"
#include "tcframe/util.hpp"

using std::runtime_error;
using std::string;

namespace tcframe {

class ArgsParser {
public:
    static Args parse(int argc, char* argv[]) {
        option longopts[] = {
                { "memory-limit",    required_argument, nullptr, 'a'},
                { "no-memory-limit", no_argument      , nullptr, 'b'},
                { "no-time-limit",   no_argument      , nullptr, 'c'},
                { "seed",            required_argument, nullptr, 'd'},
                { "solution",        required_argument, nullptr, 'e'},
                { "tc-dir",          required_argument, nullptr, 'f'},
                { "time-limit",      required_argument, nullptr, 'g'},
                { 0, 0, 0, 0 }};

        Args args;
        args.command_ = Args::Command::GEN;
        if (argc >= 2 && strcmp(argv[1], "submit") == 0) {
            args.command_ = Args::Command::SUBMIT;
            argc--;
            argv++;
        }

        optind = 1;
        opterr = 0;

        int c;
        int memoryLimit;
        unsigned seed;
        int timeLimit;
        while ((c = getopt_long_only(argc, argv, ":", longopts, nullptr)) != -1) {
            switch (c) {
                case 'a':
                    sscanf(optarg, "%d", &memoryLimit);
                    args.memoryLimit_ = optional<int>(memoryLimit);
                    break;
                case 'b':
                    args.noMemoryLimit_ = true;
                    break;
                case 'c':
                    args.noTimeLimit_ = true;
                    break;
                case 'd':
                    sscanf(optarg, "%u", &seed);
                    args.seed_ = optional<unsigned>(seed);
                    break;
                case 'e':
                    args.solution_ = optional<string>(optarg);
                    break;
                case 'f':
                    args.tcDir_ = optional<string>(optarg);
                    break;
                case 'g':
                    sscanf(optarg, "%d", &timeLimit);
                    args.timeLimit_ = optional<int>(timeLimit);
                    break;
                case ':':
                    throw runtime_error("tcframe: option " + string(argv[optind - 1]) + " requires an argument");
                case '?':
                    throw runtime_error("tcframe: option " + string(argv[optind - 1]) + " unknown");
                default:
                    break;
            }
        }

        return args;
    }
};

}
