#include "AsioTcpServer.hpp"
#include "AsioTcpConnection.hpp"
#include <functional>
#include "asio.hpp"
using namespace asio;
using namespace asio::ip;
using namespace std;

static asio::io_service g_io_service;
static void accept_handler(const asio::error_code& error)
{
  if (!error)
  {
    // Accept succeeded.
  }
}
AsioTcpServer::AsioTcpServer():
    io_service_(g_io_service),
    acceptor_(g_io_service)
{}

AsioTcpServer::~AsioTcpServer()
{
}

bool AsioTcpServer::start(int port)
{
    tcp::endpoint endpoint(tcp::v4(), port);
    acceptor_.bind(endpoint);
    AsioTcpConnetion* new_connetion(new AsioTcpConnetion(io_service_));
    acceptor_.async_accept(new_connetion->socket(),accept_handler);   
    
}