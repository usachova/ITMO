sc stop dnscache
TIMEOUT /t 5
sc queryex type=service state=all | find "SERVICE_NAME" > service2
sc start dnscache
Pause

