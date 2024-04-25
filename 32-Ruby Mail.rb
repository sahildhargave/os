require 'mail'

# Set up SMTP settings Mail.defaults do

delivery_method :smtp, {

:address => 'smtp.gmail.com',

:port => 587,

:user_name => ritish.shelke22@pccoepune.org',

:password => '',

:authentication => :login,

:enable_starttls_auto => true

}

end

# Define email message message = Mail.new do

from Ritish.shelke22@pccoepune.org' to ritishshelke007@gmail.com

subject Mail from Ruby using SMTP'

body Test mail sent!' 

end

# Send email message.deliver!

puts("mailsent");
