echo 'Setting powershell profile with location:'
echo $profile
$a = Get-Content -Path '..\MsPs_workComputer.ps1'
Set-Content -Path $profile $a
echo 'Powershell profile has been set'

