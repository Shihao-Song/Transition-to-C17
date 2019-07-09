#include <fstream>

#include "cpu_trace_cpp/cpu_trace.pb.h"

void addMicroOp(CPUTrace::MicroOp *micro_op)
{
    micro_op->set_eip(256);
    micro_op->set_opr(CPUTrace::MicroOp::LOAD);
    micro_op->set_load_or_store_addr(1024);
    micro_op->set_size(8);
}

void generate(int argc, char *argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    CPUTrace::TraceFile file;
    file.set_start(100);
    file.set_end(101);
    file.set_num_micro_ops(1);

    addMicroOp(file.add_micro_ops());

    std::ofstream output_1(argv[1]);
    if (!file.SerializeToOstream(&output_1))
    {
        std::cerr << "Failed to generate trace file. \n";
        exit(0);
    }

    /* Second output */
    file.clear_micro_ops();
    file.set_start(101);
    file.set_end(102);
    file.set_num_micro_ops(1);

    addMicroOp(file.add_micro_ops());

    std::ofstream output_2(argv[2]);
    if (!file.SerializeToOstream(&output_2))
    {
        std::cerr << "Failed to generate trace file. \n";
        exit(0);
    }

    google::protobuf::ShutdownProtobufLibrary();
}

void parse(int argc, char *argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    CPUTrace::TraceFile file;
    std::ifstream input(argv[1]);
    if (!file.ParseFromIstream(&input))
    {
        std::cerr << "Failed to parse trace file. \n";
        exit(0);
    }
    
    std::cout << "Start: " << file.start() << "\n";
    std::cout << "End: " << file.end() << "\n";
    for (int i = 0; i < file.micro_ops_size(); i++)
    {
        const CPUTrace::MicroOp &micro_op = file.micro_ops(i);
        std::cout << "Micro-Op " << i << ": \n";
        std::cout << "EIP: " << micro_op.eip() << "\n";
        if (micro_op.opr() == CPUTrace::MicroOp::LOAD)
        {
            std::cout << "Operation: LOAD \n";
        }
        std::cout << "Load Addr: " << micro_op.load_or_store_addr() << "\n";
        std::cout << "Data Size: " << micro_op.size() << "\n";
    }

    google::protobuf::ShutdownProtobufLibrary();
}

int main(int argc, char *argv[])
{
    // generate(argc, argv);
    parse(argc, argv);
}
