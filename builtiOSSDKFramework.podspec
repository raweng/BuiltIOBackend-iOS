Pod::Spec.new do |s|
s.name             = 'builtiOSSDKFramework'
s.version          = '0.0.1'
s.summary          = 'The builtiOSSDKFramework helps you create apps quickly and effortlessly, taking care of all the backend requirements.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

s.description      = <<-DESC
TODO: This SDK, or a software development kit, is like a gift box that comes with a set of software and other tools that are required to develop an application for a specific platform. With this SDK, you can now focus solely on the client side of development!
Built.io Backend works by connecting your app with our servers, using builtiOSSDKFramework  or REST APIs. You can then use Built.io Backend as your datastore, rely on it for your data validation and security needs, upload files, send push notifications…in short, you can do everything that you used to rely on a backend for without having to build it yourself!

We feature a complete set of functionalities, such as:

* Data storage
* Advanced queries on your data
* File Storage
* ACLs (Access Control Lists) for security of your data and files
* Analytics
* Webhooks, as an integration mechanism
* Push Notifications to iOS and Android devices
DESC

s.homepage         = 'https://github.com/raweng/builtiOSSDKFramework'
s.license          ={ COMMERCIAL => 'https://www.built.io' }
s.author           = { 'Built.io' => 'info@built.io' }
s.source           = { :git => 'https://github.com/raweng/builtiOSSDKFramework.git', :tag => s.version.to_s }
s.social_media_url = 'https://twitter.com/builtio'

s.ios.deployment_target = '7.0'
s.ios.vendored_frameworks = 'BuiltIOSDK/BuiltIO.framework'
s.resources = 'BuiltIOSDK/BuiltIO.bundle'

s.frameworks = 'Accounts', 'CFNetwork', 'CoreData', 'CoreGraphics', 'CoreLocation', 'CoreTelephony', 'MobileCoreServices', 'QuartzCore', 'Security', 'Social', 'SystemConfiguration'
s.libraries = 'icucore', 'sqlite3'
s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

end
