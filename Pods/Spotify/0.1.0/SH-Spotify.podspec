
Pod::Spec.new do |s|
  s.name             = 'SH-Spotify'
  s.version          = '0.1.0'
  s.summary          = '3rd party lib without CocoaPods support by author.'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.homepage         = 'http://www.stubhub.com'
  s.author           = '3rd Party'
  s.source           = { :git => "https://github.com/yuleonetscapenet/TestVendorsHack.git", :tag => "#{s.version}" }
  s.platform         = :ios, '10.0'
  s.vendored_frameworks = 'SH-Spotify/SpotifyAuthentication.framework', 'SH-Spotify/SpotifyMetadata.framework'
end
