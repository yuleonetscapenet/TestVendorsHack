
Pod::Spec.new do |s|
  s.name             = 'SHVendorPods'
  s.version          = '0.1.1'
  s.summary          = '3rd party libs without CocoaPods support.'
  s.license          = { :type => 'MIT', :text => <<-LICENSE
  Dummy text to silence license warning :)
  LICENSE
}
  s.homepage         = 'https://www.stubhub.com'
  s.author           = '3rd Parties'
  s.source           = { :git => "https://github.com/yuleonetscapenet/TestVendorsHack.git",
                        :tag => "#{s.version}"
}
  s.platform         = :ios, '12.0'
  

s.subspec 'Simility' do |simility|
  simility.source_files = "Pods/Simility/*.h"
  simility.vendored_library = "Pods/Simility/libSimilityRecon.a"
end

  s.subspec 'Veritix' do |veritix|
    veritix.vendored_frameworks = "Pods/Veritix/AXSSDKMobile.framework"
  end

end
