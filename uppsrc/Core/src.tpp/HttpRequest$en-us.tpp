topic "HttpRequest";
[2 $$0,0#00000000000000000000000000000000:Default]
[i448;a25;kKO9;2 $$1,0#37138531426314131252341829483380:class]
[l288;2 $$2,2#27521748481378242620020725143825:desc]
[0 $$3,0#96390100711032703541132217272105:end]
[H6;0 $$4,0#05600065144404261032431302351956:begin]
[i448;a25;kKO9;2 $$5,0#37138531426314131252341829483370:item]
[l288;a4;*@5;1 $$6,6#70004532496200323422659154056402:requirement]
[l288;i1121;b17;O9;~~~.1408;2 $$7,0#10431211400427159095818037425705:param]
[i448;b42;O9;2 $$8,8#61672508125594000341940100500538:tparam]
[b42;2 $$9,9#13035079074754324216151401829390:normal]
[{_}%EN-US 
[ {{10000@(113.42.0) [s0; [*@7;4 HttpRequest]]}}&]
[s3;%- &]
[s1;:HttpRequest`:`:class:%- [@(0.0.255)3 class][3 _][*3 HttpRequest][3 _:_][@(0.0.255)3 public][3 _
][*@3;3 TcpSocket]&]
[s2; &]
[s3; &]
[ {{10000F(128)G(128)@1 [s0; [* Public Method List]]}}&]
[s3;%- &]
[s5;:HttpRequest`:`:WhenContent:%- [_^Callback2^ Callback2]<[@(0.0.255) const]_[@(0.0.255) v
oid]_`*, [@(0.0.255) int]>_[* WhenContent]&]
[s2; Defines consumer function for HTTP response content. Default 
value is method inside HttpRequest that gathers the output content 
in String that can be read using GetContent method.&]
[s3;%- &]
[s4;%- &]
[s5;:HttpRequest`:`:MaxHeaderSize`(int`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* M
axHeaderSize]([@(0.0.255) int]_[*@3 m])&]
[s2; Specifies the maximum size of response header (default is 1000000). 
Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:MaxContentSize`(int`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_
[* MaxContentSize]([@(0.0.255) int]_[*@3 m])&]
[s2; Specifies the maximum size of response content (default is 10000000). 
Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:MaxRedirect`(int`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* Ma
xRedirect]([@(0.0.255) int]_[*@3 n])&]
[s2; Specifies the maximum number of redirections (code 3xx) (default 
is 5). Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:MaxRetries`(int`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* Max
Retries]([@(0.0.255) int]_[*@3 n])&]
[s2; Specifies the maximum number of retries on failure (default 
is 3). Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:RequestTimeout`(int`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_
[* RequestTimeout]([@(0.0.255) int]_[*@3 ms])&]
[s2; Specifies total allowed time for request in milliseconds (default 
is .120000 `- two minutes). Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:ChunkSize`(int`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* Chun
kSize]([@(0.0.255) int]_[*@3 n])&]
[s2; Specifies the maximum size of content data block for processing 
(default is 4096). Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Method`(int`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* Method](
[@(0.0.255) int]_[*@3 m])&]
[s2; Sets HTTP request method. [%-*@3 m] can be one of METHOD`_GET, 
METHOD`_POST, METHOD`_HEAD, METHOD`_PUT. Default setting is METHOD`_GET. 
Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:GET`(`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* GET]()&]
[s2; Same as Method(METHOD`_GET) (default). Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:POST`(`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* POST]()&]
[s2; Same as Method(METHOD`_POST). Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:HEAD`(`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* HEAD]()&]
[s2; Same as Method(METHOD`_HEAD). Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:PUT`(`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* PUT]()&]
[s2; Same as Method(METHOD`_PUT). Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Host`(const String`&`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_
[* Host]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 h])&]
[s2; Sets server host. Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Port`(int`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* Port]([@(0.0.255) i
nt]_[*@3 p])&]
[s2; Sets.server port. Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:SSL`(bool`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* SSL]([@(0.0.255) b
ool]_[*@3 b]_`=_[@(0.0.255) true])&]
[s2; Activates SSL mode. Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Path`(const String`&`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_
[* Path]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 p])&]
[s2; Sets request path. Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:User`(const String`&`,const String`&`):%- [_^HttpRequest^ HttpReque
st][@(0.0.255) `&]_[* User]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 u], 
[@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 p])&]
[s2; Sets user and password [%-*@3 u] [%-*@3 p] . Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Digest`(`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* Digest]()&]
[s2;  Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Digest`(const String`&`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&
]_[* Digest]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 d])&]
[s2;  [%-*@3 d] . Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Url`(const char`*`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* U
rl]([@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 url])&]
[s2;  [%-*@3 url] . Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:UrlVar`(const char`*`,const String`&`):%- [_^HttpRequest^ HttpReque
st][@(0.0.255) `&]_[* UrlVar]([@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 id], 
[@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 data])&]
[s2;  [%-*@3 id] [%-*@3 data] . Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:operator`(`)`(const char`*`,const String`&`):%- [_^HttpRequest^ Htt
pRequest][@(0.0.255) `&]_[* operator()]([@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 id], 
[@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 data])&]
[s2;  [%-*@3 id] [%-*@3 data] . Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:PostData`(const String`&`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&
]_[* PostData]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 pd])&]
[s2;  [%-*@3 pd] . Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:PostUData`(const String`&`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&
]_[* PostUData]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 pd])&]
[s2;  [%-*@3 pd] . Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Post`(const String`&`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_
[* Post]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 data])&]
[s2;  [%-*@3 data] . Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Post`(const char`*`,const String`&`):%- [_^HttpRequest^ HttpRequest
][@(0.0.255) `&]_[* Post]([@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 id], 
[@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 data])&]
[s2;  [%-*@3 id] [%-*@3 data] . Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Headers`(const String`&`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&
]_[* Headers]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 h])&]
[s2;  [%-*@3 h] . Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:ClearHeaders`(`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* Clea
rHeaders]()&]
[s2;  Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:AddHeaders`(const String`&`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&
]_[* AddHeaders]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 h])&]
[s2;  [%-*@3 h] . Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Header`(const char`*`,const String`&`):%- [_^HttpRequest^ HttpReque
st][@(0.0.255) `&]_[* Header]([@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 id], 
[@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 data])&]
[s2;  [%-*@3 id] [%-*@3 data] . Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Cookie`(const String`&`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&
]_[* Cookie]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 cookie])&]
[s2; Adds cookie to HTTP request. Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:StdHeaders`(bool`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* St
dHeaders]([@(0.0.255) bool]_[*@3 sh])&]
[s2;  [%-*@3 sh] . Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:NoStdHeaders`(`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_[* NoSt
dHeaders]()&]
[s2;  Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Accept`(const String`&`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&
]_[* Accept]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 a])&]
[s2;  [%-*@3 a] . Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:UserAgent`(const String`&`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&
]_[* UserAgent]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 a])&]
[s2; Specifies `"User`-Agent`" HTTP request field. Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:ContentType`(const String`&`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&
]_[* ContentType]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 a])&]
[s2; Specifies `"Content`-Type`" HTTP request field. Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Proxy`(const String`&`,int`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&
]_[* Proxy]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 host], 
[@(0.0.255) int]_[*@3 port])&]
[s2; Defines http proxy. Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Proxy`(const char`*`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&]_
[* Proxy]([@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 p])&]
[s2; Defines http proxy, [%-*@3 p] should contain `"hostname:port`". 
If port is not present, it is set to 80. Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:ProxyAuth`(const String`&`,const String`&`):%- [_^HttpRequest^ Http
Request][@(0.0.255) `&]_[* ProxyAuth]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_
[*@3 u], [@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 p])&]
[s2; Defines username and password authentication for SSL proxy. 
Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:SSLProxy`(const String`&`,int`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&
]_[* SSLProxy]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 host], 
[@(0.0.255) int]_[*@3 port])&]
[s2; Defines proxy for SSL connection. Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:SSLProxy`(const char`*`):%- [_^HttpRequest^ HttpRequest][@(0.0.255) `&
]_[* SSLProxy]([@(0.0.255) const]_[@(0.0.255) char]_`*[*@3 p])&]
[s2; Defines proxy for SSL connection, [%-*@3 p] should contain `"hostname:port`". 
If port is not present, it is set to 8080. Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:SSLProxyAuth`(const String`&`,const String`&`):%- [_^HttpRequest^ H
ttpRequest][@(0.0.255) `&]_[* SSLProxyAuth]([@(0.0.255) const]_[_^String^ String][@(0.0.255) `&
]_[*@3 u], [@(0.0.255) const]_[_^String^ String][@(0.0.255) `&]_[*@3 p])&]
[s2; Defines username and password authentication for SSL proxy. 
Returns `*this.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:IsSocketError`(`)const:%- [@(0.0.255) bool]_[* IsSocketError]()_[@(0.0.255) c
onst]&]
[s2; Returns true if there was error on socket level.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:IsHttpError`(`)const:%- [@(0.0.255) bool]_[* IsHttpError]()_[@(0.0.255) c
onst]&]
[s2; Returns true if there was error on HTTP protocol level.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:IsError`(`)const:%- [@(0.0.255) bool]_[* IsError]()_[@(0.0.255) const]&]
[s2; Same as IsSocketError() `|`| IsHttpError().&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:GetErrorDesc`(`)const:%- [_^String^ String]_[* GetErrorDesc]()_[@(0.0.255) c
onst]&]
[s2; Returns error description.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:ClearError`(`):%- [@(0.0.255) void]_[* ClearError]()&]
[s2; Clears all errors.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:GetHeader`(const char`*`):%- [_^String^ String]_[* GetHeader]([@(0.0.255) c
onst]_[@(0.0.255) char]_`*[*@3 id])&]
[s5;:HttpRequest`:`:operator`[`]`(const char`*`):%- [_^String^ String]_[* operator`[`]]([@(0.0.255) c
onst]_[@(0.0.255) char]_`*[*@3 id])&]
[s2; Returns response header field. [%-*@3 id] must be lowercase.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:GetRedirectUrl`(`):%- [_^String^ String]_[* GetRedirectUrl]()&]
[s2; Returns processed Location field of HTTP response header.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:GetContentLength`(`):%- [@(0.0.255) int]_[* GetContentLength]()&]
[s2; Returns the content length as specified in HTTP response header 
or `-1 if not specified or header not yet loaded.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:GetStatusCode`(`)const:%- [@(0.0.255) int]_[* GetStatusCode]()_[@(0.0.255) c
onst]&]
[s2; If request is finished, returns HTTP status code.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:GetReasonPhrase`(`)const:%- [_^String^ String]_[* GetReasonPhrase]()_
[@(0.0.255) const]&]
[s2; If request is finished, returns HTTP reason phrase.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:GetContent`(`)const:%- [_^String^ String]_[* GetContent]()_[@(0.0.255) c
onst]&]
[s5;:HttpRequest`:`:operator`~`(`)const:%- [_^String^ String]_[* operator`~]()_[@(0.0.255) c
onst]&]
[s5;:HttpRequest`:`:operator String`(`)const:%- [* operator_String]()_[@(0.0.255) const]&]
[s2; Returns current gather content result.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:ClearContent`(`):%- [@(0.0.255) void]_[* ClearContent]()&]
[s2; Clears the content result to reduce memory consumption. Can 
be called at any time.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Do`(`):%- [@(0.0.255) bool]_[* Do]()&]
[s2; Progresses the request. Maximum duration is defined by Socket`::Timeout. 
Returns true if processing is not finished.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:GetPhase`(`)const:%- [@(0.0.255) int]_[* GetPhase]()_[@(0.0.255) const]&]
[s2; Returns the current phase of request processing, one of BEGIN, 
START, DNS, SSLPROXYREQUEST, SSLPROXYRESPONSE, SSLHANDSHAKE, 
REQUEST, HEADER, BODY, CHUNK`_HEADER, CHUNK`_BODY, TRAILER, FINISHED, 
FAILED.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:GetPhaseName`(`)const:%- [_^String^ String]_[* GetPhaseName]()_[@(0.0.255) c
onst]&]
[s2; Returns the text description of current request phase.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:InProgress`(`)const:%- [@(0.0.255) bool]_[* InProgress]()_[@(0.0.255) c
onst]&]
[s2; Returns true if request is still in progress.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:IsFailure`(`)const:%- [@(0.0.255) bool]_[* IsFailure]()_[@(0.0.255) con
st]&]
[s2; Request has failed (it can be either due to connection errors 
or because the request did not ended with 2xx response code).&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:IsSuccess`(`)const:%- [@(0.0.255) bool]_[* IsSuccess]()_[@(0.0.255) con
st]&]
[s2; Request succeeded.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Execute`(`):%- [_^String^ String]_[* Execute]()&]
[s2; Performs the whole request, returns resulting content on success 
or String`::GetVoid() on failer.&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:HttpRequest`(`):%- [* HttpRequest]()&]
[s2; &]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:HttpRequest`(const char`*`):%- [* HttpRequest]([@(0.0.255) const]_[@(0.0.255) c
har]_`*[*@3 url])&]
[s2;  [%-*@3 url] .&]
[s3; &]
[s4; &]
[s5;:HttpRequest`:`:Trace`(bool`):%- [@(0.0.255) static] [@(0.0.255) void]_[* Trace]([@(0.0.255) b
ool]_[*@3 b]_`=_[@(0.0.255) true])&]
[s2;  [%-*@3 b] .&]
[s3; &]
[s0; ]