Pod::Spec.new do |s|
s.name             = 'BuiltIOBackend'
s.version          = '3.2.0'
s.summary          = 'The BuiltIO Backend helps you to create apps quickly and effortlessly, taking care of all the backend requirements.'

s.description      = <<-DESC
This SDK, or a software development kit, is like a gift box that comes with a set of software and other tools that are required to develop an application for a specific platform. With this SDK, you can now focus solely on the client side of development!
Built.io Backend works by connecting your app with our servers, using builtIO Backend SDK  or REST APIs. You can then use Built.io Backend as your datastore, rely on it for your data validation and security needs, upload files, send push notifications…in short, you can do everything that you used to rely on a backend for without having to build it yourself!

We feature a complete set of functionalities, such as:

* Data storage
* Advanced queries on your data
* File Storage
* ACLs (Access Control Lists) for security of your data and files
* Analytics
* Webhooks, as an integration mechanism
* Push Notifications to iOS and Android devices
DESC

s.homepage         = 'https://www.built.io/products/backend/overview'
s.license          = { :type => 'Commercial',:text => 'See https://www.built.io/'}
s.author           = { 'Built.io' => 'info@built.io' }
s.source           = { :git => 'https://github.com/raweng/BuiltIOBackend-iOS.git', :tag => s.version.to_s }
s.social_media_url = 'https://twitter.com/builtio'

s.ios.deployment_target = '7.0'
s.watchos.deployment_target = '2.0' 

s.ios.vendored_frameworks = 'SDK/iOS/BuiltIO.framework'
s.watchos.vendored_frameworks = 'SDK/watchOS/BuiltIO.framework'

s.watchos.frameworks =  'CoreGraphics','CoreLocation','MobileCoreServices', 'Security'

s.ios.frameworks = 'Accounts','CFNetwork','CoreGraphics','CoreLocation','CoreTelephony', 'MobileCoreServices','Security', 'Social','SystemConfiguration'

s.libraries = 'icucore', 'sqlite3'

s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

end
