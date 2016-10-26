#include "includes.h"
#include <bftsmart-c-server.h>

using namespace std;

namespace bftsmart {

class BftSmartServer {
public:
	virtual int appExecuteOrdered(BYTE request[], int size, BYTE ** response) = 0;
	virtual int executeUnordered(BYTE request[], int size, BYTE ** response) = 0;
	virtual int getSnapshot(BYTE ** response) = 0;
	virtual void installSnapshot(BYTE state[], int size) = 0;

protected:
	BftSmartServer(string classpath);
	~BftSmartServer();

public:
	void startServiceReplica(int id);

};

}
