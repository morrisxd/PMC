<%
Set CONNn = session("connection")
TAG=request.querystring("TAG")
PATHNAME=REQUEST.QUERYSTRING("PATHNAME")
USERNAME=REQUEST.QUERYSTRING("USERNAME")
MRID=REQUEST.QUERYSTRING("MRID")
BRANCH=REQUEST.QUERYSTRING("BRANCH")

QS="UPDATE FILELIST SET RESERVED1='" + tag + "' WHERE PATHNAME='"+PATHNAME+"' and mrid='" + MRID + "' and RESERVED2='"+ BRANCH +"'"
RESPONSE.WRITE(QS)
CONNn.execute(qs)
%>