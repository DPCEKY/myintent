#include "HeapSort.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <iostream>
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace std;
using boost::shared_ptr;

using namespace  ::test::thrift;

int main(){
        shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
        shared_ptr<TTransport> transport(new TBufferedTransport(socket));
        shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

        HeapSortClient  client(protocol);
        transport->open();
        
        vector<int32_t> A;
        cout << "Input the number to be sorted, terminating with #:" << endl;
        char InputChar[20];
        while( 1 )
        {
            cin >> InputChar;
            if( '#' == *InputChar )
                break;
            A.push_back( atoi( InputChar ) );

        }
        vector<int32_t> returnA(A);
        client.HeapSort( returnA, A, A.size() );
        for( int i = A.capacity(); i >= 0; i-- ) 
            cout << returnA.at(i) << endl;

        transport->close();

        return 0;
}
