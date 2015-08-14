Introduction
-
WebFTP client can be used to upload files over HTTP to a web service. This application is intended to replace the default Windows FTP client. This application increases the performance of the uploads by taking advantages of the scalability and performance of HTTP protocol.

How to use
--
webtpclient [url] [-U:username] [-P:password] [-F:file(s)] [-D:folder] [-s]

        [url]   Webftp server path url
         -U             Username
         -P             Password
         -F             Source file name, or pattern (ex: filename.txt, *.txt)
         -D             Specify destination sub-folder name (Optional)
         -S             Suppresses output (Optional)
         
        Usage Example:  

        WebFtpClient http://127.0.0.1 -u:myuser -p:mypass -f:abc.csv
        WebFtpClient http://127.0.0.1 -u:myuser -p:mypass -f:myfile.csv -s
        WebFtpClient http://127.0.0.1 -u:myuser -u:mypass -f:*.txt -d:mySubFolder -S
        
Note: You can use upper-case or lower-case switches. They function identically.

Backend Implementation
--

Webftp client uses a multipart HTTP POST request to the server with the following variables in the post:

        POST-FILE:      <base64 encoded data>
        CONTENT-TYPE:   multipart/form-data
The server should implement a RESTful API which accepts the following variable in URL:

        username        The username to be used for authentication (Required)
        password        The password to be used for authentication (Required)
        subfolder       The destination subfolder (Optional)
        
Endpoint URL

An example of an URL endpoint is as followed:

https://127.0.0.1/Upload?username=test&password=123&subfolder=abc

Reesponse Data

Currently, response data from server is not being processed and is only being output to the console. However, it is possible to parse the response data easily if retuned in JSON format.
