Webftp Client v1.0  -  5/12/2014

INTRODUCTION
------------

Webftp client can be used to upload files over HTTP to a Webftp web service. This application
is intended to replace the Windows ftp default client. This application increases the performance
of the uploads by taking advantage of the scalability and performance of HTTP protocol.

=================================================================================================

HOW TO USE 
----------

webtpclient [url] [-U:username] [-P:password] [-F:file(s)] [-D:folder] [-s]

	[url]	Webftp server path url
	 -U		Username
	 -P		Password
	 -F		Source file name, or pattern (ex: filename.txt, *.txt)
	 -D		Specify destination sub-folder name (Optional)
	 -S		Suppresses output (Optional)
	 
	Usage Example:  

	WebFtpClient http://127.0.0.1 -u:myuser -p:mypass -f:abc.csv
	WebFtpClient http://127.0.0.1 -u:myuser -p:mypass -f:myfile.csv -s
	WebFtpClient http://127.0.0.1 -u:myuser -u:mypass -f:*.txt -d:mySubFolder -S

Note: You can use upper-case or lower-case switches. They function identically.

=================================================================================================
COPYRIGHT AND PERMISSION NOTICE
-------------------------------

Copyright 2014 Motor Vehicle Software Corporation.  
All Rights Reserved.
http://www.mvscusa.com


All  information contained  herein is,  and  remains the property 
of  Motor Vehicle Software Corporation ("MVSC"). The intellectual 
and  technical  concepts contained herein are proprietary to MVSC
and is covered by U.S. and Foreign Patents, patents in process,
and are protected by trade secret or copyright law. Dissemination 
of this information, redistribution or reproduction of this material
is strictly forbidden unless prior written permission is obtained 
from Motor Vehicle Software Corporation.



