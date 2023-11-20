This is webserv, a 42 School project.

Webserv is a web-server compatible with a subset of
HTTP 1.1. 

- developed in c++ on Ubuntu 20.04, should be compatible
with linux systems but has not (yet) been tested with other
unix systems. 
- MULTIPLEXING is being handled through EPOLL, making this
software not compatible with MacOs or Windows.
- Only Localhost has been tested. Basic Virtual Servers
(multiple servers on the same ip:port pair) are mostly implemented.
- No Cookies system is implemented (but should be easy to do).
- GET, POST, DELETE are the only http methods implemented.

- NGNIX-like syntax is being used for configuration files. A few
configuration files are provided, aswell as a www directory containing
a few static pages meant for showcasing the webserver functionality:
-- The server handles Python, Ruby, Perl CGIs:
--- /cgi-bin/home.py -> a python script generating a basic landing page.
-- a couple of POST methods are implemented:
--- /upload_file2.html -> to test MULTIPART POST
--- < curl -X POST -H "Transfer-Encoding: chunked" --data-binary @reg.txt 127.0.0.1:8080/gallery/ > -> to test chunked POST method

This software is provided as-is. Many comments are still present in the code
which is a team-work of:
- Tommaso Di Leo (myself)
- Kevin Krzysztof Zak
- Catia Filiberto

