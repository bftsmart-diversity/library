#include "bftsmart-server.hpp"

namespace bftsmart
{

/** Wrapper que possibilita a chamada de métodos da classe
 *  C++ a partir de C. Não é possível chamar um método de
 *  instância de C++ a partir de C, portanto a classe
 *  FunctionCall faz um wrapper sobre esses métodos,
 *  expondo métodos estáticos que então podem ser chamados
 *  a partir de C.
 */
class FunctionCall {
public:
    static bftsmart::BftSmartServer* instance;
    static int callExecOrd(BYTE req[], int sz, BYTE**resp);
    static int callExecUnord(BYTE req[], int sz, BYTE**resp);
    static int callgetsnap(BYTE** resp);
    static void callinstall(BYTE stt[], int sz);
    static void callRelease(BYTE mem[]);
};
}

bftsmart::BftSmartServer* bftsmart::FunctionCall::instance;

int bftsmart::FunctionCall::callExecOrd(BYTE req[], int sz, BYTE**resp) {
	return instance->appExecuteOrdered(req,sz,resp);
}

int bftsmart::FunctionCall::callExecUnord(BYTE req[], int sz, BYTE**resp) {
	return instance->executeUnordered(req,sz,resp);
}

int bftsmart::FunctionCall::callgetsnap(BYTE** resp) {
	return instance->getSnapshot(resp);
}

void bftsmart::FunctionCall::callinstall(BYTE stt[], int sz) {
	instance->installSnapshot(stt,sz);
}

void bftsmart::FunctionCall::callRelease(BYTE mem[]) {
	free(mem);
}

bftsmart::BftSmartServer::BftSmartServer(string classpath)
{
	setClasspath(classpath.c_str());
	carregarJvm();
        bftsmart::FunctionCall::instance = this;
	implementExecuteOrdered(&bftsmart::FunctionCall::callExecOrd);
	implementExecuteUnordered(&bftsmart::FunctionCall::callExecUnord);
	implementgetSnapshot(&bftsmart::FunctionCall::callgetsnap);
	implementInstallSnapshot(&bftsmart::FunctionCall::callinstall);
	implementReleaseGetSnapshotBuffer(&bftsmart::FunctionCall::callRelease);
	implementReleaseExecuteOrderedBuffer(&bftsmart::FunctionCall::callRelease);
	implementReleaseExecuteUnorderedBuffer(&bftsmart::FunctionCall::callRelease);
}

void bftsmart::BftSmartServer::startServiceReplica(int id)
{
	startServiceReplica(id);
}

bftsmart::BftSmartServer::~BftSmartServer()
{
	finalizarJvm();
}
