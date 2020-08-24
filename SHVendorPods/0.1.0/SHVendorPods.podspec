
Pod::Spec.new do |s|
  s.name             = 'SHVendorPods'
  s.version          = '0.1.0'
  s.summary          = '3rd party libs without CocoaPods support.'
  s.license          = { :type => 'MIT', :text => <<-LICENSE
  Dummy text to silence license warning :)
  LICENSE
}
  s.homepage         = 'http://www.stubhub.com'
  s.author           = '3rd Parties'
  s.source           = { :git => "git@github.com:stubhub/native-ios-vendor-deps.git", :commit => "d0ce3b9ba9ab8225139532aa64541cb3e2f4d507" }
  s.platform         = :ios, '10.0'
  
  s.subspec 'Distil' do |distil|
    distil.vendored_frameworks = "Pods/Distil/distil_protection.framework"
  end

  s.subspec 'QuantumMetric' do |qm|
    qm.source_files = "Pods/QuantumMetric/*.h"
    qm.vendored_library = "Pods/QuantumMetric/libQMNative.a"
  end

  s.subspec 'Simility' do |simility|
    simility.source_files = "Pods/Simility/*.h"
    simility.vendored_library = "Pods/Simility/libSimilityRecon.a"
  end

  s.subspec 'Spotify' do |spotify|
    spotify.vendored_frameworks = 'Pods/Spotify/SpotifyAuthentication.framework', 'Pods/Spotify/SpotifyMetadata.framework'
  end

  s.subspec 'Veritix' do |veritix|
    veritix.vendored_frameworks = "Pods/Veritix/AXSSDKMobile.framework"
  end

end
