TABLE_(USERS)
   STRING_		(EMAIL, 50) PRIMARY_KEY
   STRING_		(NAME, 200)
   STRING_		(SURNAME, 200)
   STRING_		(ADDRESS, 200)
   STRING_		(TOWN, 50)
   STRING_		(ZONE, 20)
   STRING_		(COUNTRY, 50)
   STRING_		(ZIP, 20)
   INT_			(CATHEGORY)
   STRING_		(CF, 50)
   STRING_		(PIVA, 50)
   STRING_		(PHONE, 50)
   STRING_		(FAX, 50)
   STRING_		(CELL, 50)
   TIME_		(EXPIRATION)
   INT_			(LICENSES)
   STRING_		(ALLOWEDVERSION, 20)
   STRING_		(ACTIVATIONKEY, 200)
   TIME_		(REGISTRATIONDATE)
   BOOL_		(ACTIVATED)
   TIME_		(ACTIVATIONDATE)
   TIME_		(LASTCONNECTIONDATE)
   INT_			(TOTALCONNECTIONS)
   INT_			(TOTALCONNECTIONTIME)
END_TABLE
